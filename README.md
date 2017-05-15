# seteuid
Seteuid example with explanation
There are two cases,

You want to temporarily drop root privilege while executing setuid program
You want to permanently drop root privilege while executing setuid program...
You can temporarily do it by setting the euid to the real user id and then changing the uid to anything you want.And later when you need the root privilege back you can setuid to root and the effective userid will change back to root. This is because the saved user id is not changed.
You can drop privilege permanently by changing the uid straight away to a lesser privileged user id. After this no matter what you cannot get back the root privilege.
Case 1:

After a setuid program starts executing

1.seteuid(600);
2.setuid(1000);
3.setuid(0);
For this case the root privilege can be gained back again.

              +----+------+------------+
              | uid|euid  |saved-uid   |
              |----|------|------------|
            1.|1000| 0    | 0          |
            2.|1000| 600  | 0          |
            3.|1000| 1000 | 0          |
            4.|1000|  0   | 0          |
              |    |      |            |
              +------------------------+
Case 2:

After a setuid program starts executing,

1.setuid(1000);
2.setuid(0);



               +----+------+------------+
               | uid|euid  |saved-uid   |
               |----|------|------------|
             1.|1000|0     | 0          |
             2.|1000|1000  | 1000       |
               |    |      |            |
               +------------------------+
In this case you cannot get back the root privilege. This can be verified by the following command,

cat /proc/PROCID/task/PROCID/status | less

Uid:    1000    0       0       0
Gid:    1000    0       0       0
This command will display a Uid and Gid and it will have 4 fields( the first three fields are the one we are concerned with). Something like the above

The three fields represent uid,euid and saved-user-id. You can introduce a pause (an input from user) in your setuid program and check for each step the cat /proc/PROCID/task/PROCID/status | less command. During each step you can check the saved uid getting changed as mentioned.

If you're euid is root and you change the uid, the privileges gets dropped permanently.If effective user id is not root then saved user id is never touched and you can regain the root privilege back anytime you want in your program.
