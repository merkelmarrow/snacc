# Terms
- Parallelism: Dividing a single task into parts and running each in parallel.

# Notes
Gitignore tells git what files and directories to exclude from version control, use it to keep the repo clean from unnecessary temp files.
## gRPC
gRPC stands for gRPC Remote Procedure Call.
Protocol buffers are an easy and efficient method to serialise strucutured data. Smaller and faster than JSON.

Protobuf files -> Protobuf generator -> Generated source code

In gRPC, a client application can directly call a method on a different machine as if it were a local object. Define a service, specify the methods that can be called remotely, their paramaters and return types.

The first step when using protocol buffers is defining a structure for the data you want to serialise in a proto file (txt with .proto). Protobuf is structured as _messages_. Name value pairs.

```protobuf
message Person {
  string name = 1;
  int32 id = 2;
}
```

Protobuf compiler "protoc" generates data access classes. The provide accessors for each field, ie name(), also methods to serialise and parse raw bytes.

```protobuf
service Greeter {
  rpc SayHello (HelloRequest) returns (HelloReply) {}
}

message HelloRequest {
   string name = 1;
}

message HelloReply {
  string message = 1;
}
```


# Dev Log
## 29/12/2024
Created VS project (CMake Project).
## 30/12/2024
Learning gRPC and protocol buffers.
## 02/01/2025
Following gRPC health check guide.
