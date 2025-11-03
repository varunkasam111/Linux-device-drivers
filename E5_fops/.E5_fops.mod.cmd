cmd_/home/pe-rnd3/BBB/MyLKMs/E5_fops/E5_fops.mod := printf '%s\n'   E5_fops.o | awk '!x[$$0]++ { print("/home/pe-rnd3/BBB/MyLKMs/E5_fops/"$$0) }' > /home/pe-rnd3/BBB/MyLKMs/E5_fops/E5_fops.mod
