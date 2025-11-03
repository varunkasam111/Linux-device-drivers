cmd_/home/pe-rnd3/BBB/MyLKMs/E1_test/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/pe-rnd3/BBB/MyLKMs/E1_test/"$$0) }' > /home/pe-rnd3/BBB/MyLKMs/E1_test/hello.mod
