/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef log_store_service_H
#define log_store_service_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "server/log_store_types.h"

namespace datastore {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class log_store_serviceIf {
 public:
  virtual ~log_store_serviceIf() {}
  virtual int64_t append(const std::string& data) = 0;
  virtual void get(std::string& _return, const int64_t id) = 0;
  virtual bool update(const int64_t id, const std::string& data) = 0;
  virtual bool invalidate(const int64_t id) = 0;
  virtual int64_t begin_snapshot() = 0;
  virtual bool end_snapshot(const int64_t id) = 0;
};

class log_store_serviceIfFactory {
 public:
  typedef log_store_serviceIf Handler;

  virtual ~log_store_serviceIfFactory() {}

  virtual log_store_serviceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(log_store_serviceIf* /* handler */) = 0;
};

class log_store_serviceIfSingletonFactory : virtual public log_store_serviceIfFactory {
 public:
  log_store_serviceIfSingletonFactory(const boost::shared_ptr<log_store_serviceIf>& iface) : iface_(iface) {}
  virtual ~log_store_serviceIfSingletonFactory() {}

  virtual log_store_serviceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(log_store_serviceIf* /* handler */) {}

 protected:
  boost::shared_ptr<log_store_serviceIf> iface_;
};

class log_store_serviceNull : virtual public log_store_serviceIf {
 public:
  virtual ~log_store_serviceNull() {}
  int64_t append(const std::string& /* data */) {
    int64_t _return = 0;
    return _return;
  }
  void get(std::string& /* _return */, const int64_t /* id */) {
    return;
  }
  bool update(const int64_t /* id */, const std::string& /* data */) {
    bool _return = false;
    return _return;
  }
  bool invalidate(const int64_t /* id */) {
    bool _return = false;
    return _return;
  }
  int64_t begin_snapshot() {
    int64_t _return = 0;
    return _return;
  }
  bool end_snapshot(const int64_t /* id */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _log_store_service_append_args__isset {
  _log_store_service_append_args__isset() : data(false) {}
  bool data :1;
} _log_store_service_append_args__isset;

class log_store_service_append_args {
 public:

  log_store_service_append_args(const log_store_service_append_args&);
  log_store_service_append_args& operator=(const log_store_service_append_args&);
  log_store_service_append_args() : data() {
  }

  virtual ~log_store_service_append_args() throw();
  std::string data;

  _log_store_service_append_args__isset __isset;

  void __set_data(const std::string& val);

  bool operator == (const log_store_service_append_args & rhs) const
  {
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const log_store_service_append_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_append_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_append_pargs {
 public:


  virtual ~log_store_service_append_pargs() throw();
  const std::string* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_append_result__isset {
  _log_store_service_append_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_append_result__isset;

class log_store_service_append_result {
 public:

  log_store_service_append_result(const log_store_service_append_result&);
  log_store_service_append_result& operator=(const log_store_service_append_result&);
  log_store_service_append_result() : success(0) {
  }

  virtual ~log_store_service_append_result() throw();
  int64_t success;

  _log_store_service_append_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const log_store_service_append_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_append_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_append_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_append_presult__isset {
  _log_store_service_append_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_append_presult__isset;

class log_store_service_append_presult {
 public:


  virtual ~log_store_service_append_presult() throw();
  int64_t* success;

  _log_store_service_append_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _log_store_service_get_args__isset {
  _log_store_service_get_args__isset() : id(false) {}
  bool id :1;
} _log_store_service_get_args__isset;

class log_store_service_get_args {
 public:

  log_store_service_get_args(const log_store_service_get_args&);
  log_store_service_get_args& operator=(const log_store_service_get_args&);
  log_store_service_get_args() : id(0) {
  }

  virtual ~log_store_service_get_args() throw();
  int64_t id;

  _log_store_service_get_args__isset __isset;

  void __set_id(const int64_t val);

  bool operator == (const log_store_service_get_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const log_store_service_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_get_pargs {
 public:


  virtual ~log_store_service_get_pargs() throw();
  const int64_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_get_result__isset {
  _log_store_service_get_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_get_result__isset;

class log_store_service_get_result {
 public:

  log_store_service_get_result(const log_store_service_get_result&);
  log_store_service_get_result& operator=(const log_store_service_get_result&);
  log_store_service_get_result() : success() {
  }

  virtual ~log_store_service_get_result() throw();
  std::string success;

  _log_store_service_get_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const log_store_service_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_get_presult__isset {
  _log_store_service_get_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_get_presult__isset;

class log_store_service_get_presult {
 public:


  virtual ~log_store_service_get_presult() throw();
  std::string* success;

  _log_store_service_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _log_store_service_update_args__isset {
  _log_store_service_update_args__isset() : id(false), data(false) {}
  bool id :1;
  bool data :1;
} _log_store_service_update_args__isset;

class log_store_service_update_args {
 public:

  log_store_service_update_args(const log_store_service_update_args&);
  log_store_service_update_args& operator=(const log_store_service_update_args&);
  log_store_service_update_args() : id(0), data() {
  }

  virtual ~log_store_service_update_args() throw();
  int64_t id;
  std::string data;

  _log_store_service_update_args__isset __isset;

  void __set_id(const int64_t val);

  void __set_data(const std::string& val);

  bool operator == (const log_store_service_update_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const log_store_service_update_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_update_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_update_pargs {
 public:


  virtual ~log_store_service_update_pargs() throw();
  const int64_t* id;
  const std::string* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_update_result__isset {
  _log_store_service_update_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_update_result__isset;

class log_store_service_update_result {
 public:

  log_store_service_update_result(const log_store_service_update_result&);
  log_store_service_update_result& operator=(const log_store_service_update_result&);
  log_store_service_update_result() : success(0) {
  }

  virtual ~log_store_service_update_result() throw();
  bool success;

  _log_store_service_update_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const log_store_service_update_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_update_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_update_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_update_presult__isset {
  _log_store_service_update_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_update_presult__isset;

class log_store_service_update_presult {
 public:


  virtual ~log_store_service_update_presult() throw();
  bool* success;

  _log_store_service_update_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _log_store_service_invalidate_args__isset {
  _log_store_service_invalidate_args__isset() : id(false) {}
  bool id :1;
} _log_store_service_invalidate_args__isset;

class log_store_service_invalidate_args {
 public:

  log_store_service_invalidate_args(const log_store_service_invalidate_args&);
  log_store_service_invalidate_args& operator=(const log_store_service_invalidate_args&);
  log_store_service_invalidate_args() : id(0) {
  }

  virtual ~log_store_service_invalidate_args() throw();
  int64_t id;

  _log_store_service_invalidate_args__isset __isset;

  void __set_id(const int64_t val);

  bool operator == (const log_store_service_invalidate_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const log_store_service_invalidate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_invalidate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_invalidate_pargs {
 public:


  virtual ~log_store_service_invalidate_pargs() throw();
  const int64_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_invalidate_result__isset {
  _log_store_service_invalidate_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_invalidate_result__isset;

class log_store_service_invalidate_result {
 public:

  log_store_service_invalidate_result(const log_store_service_invalidate_result&);
  log_store_service_invalidate_result& operator=(const log_store_service_invalidate_result&);
  log_store_service_invalidate_result() : success(0) {
  }

  virtual ~log_store_service_invalidate_result() throw();
  bool success;

  _log_store_service_invalidate_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const log_store_service_invalidate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_invalidate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_invalidate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_invalidate_presult__isset {
  _log_store_service_invalidate_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_invalidate_presult__isset;

class log_store_service_invalidate_presult {
 public:


  virtual ~log_store_service_invalidate_presult() throw();
  bool* success;

  _log_store_service_invalidate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class log_store_service_begin_snapshot_args {
 public:

  log_store_service_begin_snapshot_args(const log_store_service_begin_snapshot_args&);
  log_store_service_begin_snapshot_args& operator=(const log_store_service_begin_snapshot_args&);
  log_store_service_begin_snapshot_args() {
  }

  virtual ~log_store_service_begin_snapshot_args() throw();

  bool operator == (const log_store_service_begin_snapshot_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const log_store_service_begin_snapshot_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_begin_snapshot_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_begin_snapshot_pargs {
 public:


  virtual ~log_store_service_begin_snapshot_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_begin_snapshot_result__isset {
  _log_store_service_begin_snapshot_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_begin_snapshot_result__isset;

class log_store_service_begin_snapshot_result {
 public:

  log_store_service_begin_snapshot_result(const log_store_service_begin_snapshot_result&);
  log_store_service_begin_snapshot_result& operator=(const log_store_service_begin_snapshot_result&);
  log_store_service_begin_snapshot_result() : success(0) {
  }

  virtual ~log_store_service_begin_snapshot_result() throw();
  int64_t success;

  _log_store_service_begin_snapshot_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const log_store_service_begin_snapshot_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_begin_snapshot_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_begin_snapshot_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_begin_snapshot_presult__isset {
  _log_store_service_begin_snapshot_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_begin_snapshot_presult__isset;

class log_store_service_begin_snapshot_presult {
 public:


  virtual ~log_store_service_begin_snapshot_presult() throw();
  int64_t* success;

  _log_store_service_begin_snapshot_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _log_store_service_end_snapshot_args__isset {
  _log_store_service_end_snapshot_args__isset() : id(false) {}
  bool id :1;
} _log_store_service_end_snapshot_args__isset;

class log_store_service_end_snapshot_args {
 public:

  log_store_service_end_snapshot_args(const log_store_service_end_snapshot_args&);
  log_store_service_end_snapshot_args& operator=(const log_store_service_end_snapshot_args&);
  log_store_service_end_snapshot_args() : id(0) {
  }

  virtual ~log_store_service_end_snapshot_args() throw();
  int64_t id;

  _log_store_service_end_snapshot_args__isset __isset;

  void __set_id(const int64_t val);

  bool operator == (const log_store_service_end_snapshot_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const log_store_service_end_snapshot_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_end_snapshot_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class log_store_service_end_snapshot_pargs {
 public:


  virtual ~log_store_service_end_snapshot_pargs() throw();
  const int64_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_end_snapshot_result__isset {
  _log_store_service_end_snapshot_result__isset() : success(false) {}
  bool success :1;
} _log_store_service_end_snapshot_result__isset;

class log_store_service_end_snapshot_result {
 public:

  log_store_service_end_snapshot_result(const log_store_service_end_snapshot_result&);
  log_store_service_end_snapshot_result& operator=(const log_store_service_end_snapshot_result&);
  log_store_service_end_snapshot_result() : success(0) {
  }

  virtual ~log_store_service_end_snapshot_result() throw();
  bool success;

  _log_store_service_end_snapshot_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const log_store_service_end_snapshot_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const log_store_service_end_snapshot_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const log_store_service_end_snapshot_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _log_store_service_end_snapshot_presult__isset {
  _log_store_service_end_snapshot_presult__isset() : success(false) {}
  bool success :1;
} _log_store_service_end_snapshot_presult__isset;

class log_store_service_end_snapshot_presult {
 public:


  virtual ~log_store_service_end_snapshot_presult() throw();
  bool* success;

  _log_store_service_end_snapshot_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class log_store_serviceClient : virtual public log_store_serviceIf {
 public:
  log_store_serviceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  log_store_serviceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t append(const std::string& data);
  void send_append(const std::string& data);
  int64_t recv_append();
  void get(std::string& _return, const int64_t id);
  void send_get(const int64_t id);
  void recv_get(std::string& _return);
  bool update(const int64_t id, const std::string& data);
  void send_update(const int64_t id, const std::string& data);
  bool recv_update();
  bool invalidate(const int64_t id);
  void send_invalidate(const int64_t id);
  bool recv_invalidate();
  int64_t begin_snapshot();
  void send_begin_snapshot();
  int64_t recv_begin_snapshot();
  bool end_snapshot(const int64_t id);
  void send_end_snapshot(const int64_t id);
  bool recv_end_snapshot();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class log_store_serviceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<log_store_serviceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (log_store_serviceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_append(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_update(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_invalidate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_begin_snapshot(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_end_snapshot(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  log_store_serviceProcessor(boost::shared_ptr<log_store_serviceIf> iface) :
    iface_(iface) {
    processMap_["append"] = &log_store_serviceProcessor::process_append;
    processMap_["get"] = &log_store_serviceProcessor::process_get;
    processMap_["update"] = &log_store_serviceProcessor::process_update;
    processMap_["invalidate"] = &log_store_serviceProcessor::process_invalidate;
    processMap_["begin_snapshot"] = &log_store_serviceProcessor::process_begin_snapshot;
    processMap_["end_snapshot"] = &log_store_serviceProcessor::process_end_snapshot;
  }

  virtual ~log_store_serviceProcessor() {}
};

class log_store_serviceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  log_store_serviceProcessorFactory(const ::boost::shared_ptr< log_store_serviceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< log_store_serviceIfFactory > handlerFactory_;
};

class log_store_serviceMultiface : virtual public log_store_serviceIf {
 public:
  log_store_serviceMultiface(std::vector<boost::shared_ptr<log_store_serviceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~log_store_serviceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<log_store_serviceIf> > ifaces_;
  log_store_serviceMultiface() {}
  void add(boost::shared_ptr<log_store_serviceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int64_t append(const std::string& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->append(data);
    }
    return ifaces_[i]->append(data);
  }

  void get(std::string& _return, const int64_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(_return, id);
    }
    ifaces_[i]->get(_return, id);
    return;
  }

  bool update(const int64_t id, const std::string& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->update(id, data);
    }
    return ifaces_[i]->update(id, data);
  }

  bool invalidate(const int64_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->invalidate(id);
    }
    return ifaces_[i]->invalidate(id);
  }

  int64_t begin_snapshot() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->begin_snapshot();
    }
    return ifaces_[i]->begin_snapshot();
  }

  bool end_snapshot(const int64_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->end_snapshot(id);
    }
    return ifaces_[i]->end_snapshot(id);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class log_store_serviceConcurrentClient : virtual public log_store_serviceIf {
 public:
  log_store_serviceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  log_store_serviceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t append(const std::string& data);
  int32_t send_append(const std::string& data);
  int64_t recv_append(const int32_t seqid);
  void get(std::string& _return, const int64_t id);
  int32_t send_get(const int64_t id);
  void recv_get(std::string& _return, const int32_t seqid);
  bool update(const int64_t id, const std::string& data);
  int32_t send_update(const int64_t id, const std::string& data);
  bool recv_update(const int32_t seqid);
  bool invalidate(const int64_t id);
  int32_t send_invalidate(const int64_t id);
  bool recv_invalidate(const int32_t seqid);
  int64_t begin_snapshot();
  int32_t send_begin_snapshot();
  int64_t recv_begin_snapshot(const int32_t seqid);
  bool end_snapshot(const int64_t id);
  int32_t send_end_snapshot(const int64_t id);
  bool recv_end_snapshot(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
