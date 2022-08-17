[Protobuf官方教程](https://developers.google.com/protocol-buffers/docs/cpptutorial)

1. 使用xxx.proto文件生成xxx.pb.cc和xxx.pb.h文件
```shell
/usr/local/protobuf/bin/protoc --cpp_out=./ addressbook.proto
```
可使用的api：
```C++
  // name
  inline bool has_name() const;
  inline void clear_name();
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline ::std::string* mutable_name();

  // id
  inline bool has_id() const;
  inline void clear_id();
  inline int32_t id() const;
  inline void set_id(int32_t value);

  // email
  inline bool has_email() const;
  inline void clear_email();
  inline const ::std::string& email() const;
  inline void set_email(const ::std::string& value);
  inline void set_email(const char* value);
  inline ::std::string* mutable_email();

  // phones
  inline int phones_size() const;
  inline void clear_phones();
  inline const ::google::protobuf::RepeatedPtrField< ::tutorial::Person_PhoneNumber >& phones() const;
  inline ::google::protobuf::RepeatedPtrField< ::tutorial::Person_PhoneNumber >* mutable_phones();
  inline const ::tutorial::Person_PhoneNumber& phones(int index) const;
  inline ::tutorial::Person_PhoneNumber* mutable_phones(int index);
  inline ::tutorial::Person_PhoneNumber* add_phones();
```
2. 指定编译所需要的库和文件，生成读写消息的可执行文件
```shell
g++ read.cpp address.pb.cc -o read -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf
g++ read.cpp addressbook.pb.cc -o read -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf
```
3. 测试
```
wydxry@ubuntu:~/mpzRPC/test/protobuf$ g++ write.cpp addressbook.pb.cc -o write -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf
wydxry@ubuntu:~/mpzRPC/test/protobuf$ ./write file
file: File not found.  Creating a new file.
Enter person ID number: 1
Enter name: a
Enter email address (blank for none):  
Enter a phone number (or leave blank to finish):  
Is this a mobile, home, or work phone? 
Unknown phone type.  Using default.
Enter a phone number (or leave blank to finish):  
Is this a mobile, home, or work phone?  
Unknown phone type.  Using default.
Enter a phone number (or leave blank to finish): 
wydxry@ubuntu:~/mpzRPC/test/protobuf$ g++ read.cpp addressbook.pb.cc -o read -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf
wydxry@ubuntu:~/mpzRPC/test/protobuf$ ./read file 
Person ID: 1
  Name: a
  E-mail address:  
  Mobile phone #:  
  Mobile phone #:  
wydxry@ubuntu:~/mpzRPC/test/protobuf$ ./write file
Enter person ID number: 2
Enter name: b
Enter email address (blank for none): wydxry@163.com
Enter a phone number (or leave blank to finish): 123
Is this a mobile, home, or work phone?  
Unknown phone type.  Using default.
Enter a phone number (or leave blank to finish):  
Is this a mobile, home, or work phone?  
Unknown phone type.  Using default.
Enter a phone number (or leave blank to finish): 
wydxry@ubuntu:~/mpzRPC/test/protobuf$ ./read file
Person ID: 1
  Name: a
  E-mail address:  
  Mobile phone #:  
  Mobile phone #:  
Person ID: 2
  Name: b
  E-mail address: wydxry@163.com
  Mobile phone #: 123
  Mobile phone #:  
```
