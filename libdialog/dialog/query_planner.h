#ifndef DIALOG_QUERY_PLANNER_H_
#define DIALOG_QUERY_PLANNER_H_

#include <unordered_map>

#include "compiled_expression.h"
#include "radix_tree.h"
#include "auxlog.h"
#include "query_plan.h"

namespace dialog {

class query_planner {
 public:
  typedef std::vector<index_filter> index_filters;
  typedef index_filters::iterator if_iterator;
  typedef index_filters::const_iterator const_if_iterator;

  query_planner(const compiled_expression& expr,
                const index_list_type& idx_list)
      : expr_(expr),
        idx_list_(idx_list) {
  }

  query_plan plan() {
    query_plan qp;
    for (const minterm& m : expr_) {
      index_filters filters = reduce_filters(get_filters(m));
      if (!filters.empty()) {
        size_t min_filter_idx = min_filter(filters);
        minterm_plan mplan = minterm_plan(filters[min_filter_idx], m);
        qp.push_back(mplan);
      }
    }
    return qp;
  }

 private:
  size_t min_filter(const index_filters& filters) {
    if (filters.size() == 1) {
      return 0;
    }

    size_t min_idx = 0;
    size_t min_count = UINT64_MAX;

    for (size_t i = 0; i < filters.size(); i++) {
      uint64_t count;
      if ((count = idx_list_.at(filters.at(i).index_id())->approx_count(
          filters.at(i).kbegin(), filters.at(i).kend()))) {
        min_count = count;
        min_idx = i;
      }
    }

    return min_idx;
  }

  index_filters get_filters(const minterm& m) {
    index_filters filters;
    for (const compiled_predicate& p : m) {
      if (p.is_indexed()) {
        index_filters f = p.idx_filters();
        filters.insert(filters.end(), f.begin(), f.end());
      }
    }
    return filters;
  }

  index_filters reduce_filters(const index_filters& filters) {
    index_filters out;
    std::unordered_map<uint32_t, std::vector<size_t>> filter_map;
    for (size_t i = 0; i < filters.size(); i++)
      filter_map[filters.at(i).index_id()].push_back(i);

    for (auto entry : filter_map) {
      auto kbegin = filters[entry.second[0]].kbegin();
      auto kend = filters[entry.second[0]].kend();
      for (size_t j = 1; j < entry.second.size(); j++) {
        kbegin =
            kbegin > filters[entry.second[j]].kbegin() ?
                kbegin : filters[entry.second[j]].kbegin();
        kend =
            kend < filters[entry.second[j]].kend() ?
                kend : filters[entry.second[j]].kend();
      }
      if (kbegin <= kend)
        out.push_back(index_filter(entry.first, kbegin, kend));
      else
        return {};
    }
    return out;
  }

  compiled_expression expr_;
  const index_list_type& idx_list_;
};

}

#endif /* DIALOG_QUERY_PLANNER_H_ */