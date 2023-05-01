cmd_/home/kbritto/ECGR-6181/Lab4/mem.mod := printf '%s\n'   mem.o | awk '!x[$$0]++ { print("/home/kbritto/ECGR-6181/Lab4/"$$0) }' > /home/kbritto/ECGR-6181/Lab4/mem.mod
