{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ "hello.cc", "hello-tp.c" ],
      "include_dirs": [ "./" ],
      "libraries": [ "-llttng-ust" ]
    }
  ]
}
