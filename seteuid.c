int main(void) {
    printf(
        "         UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );

seteuid(600);
    printf(
        "         UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );

setuid(1000);

    printf(
        "         UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );

setuid(0); // HOW DOES THIS SUCCEED IN SETTING THE EUID BACK TO 0
    printf(
        "         UID           GID  \n"
        "Real      %d  Real      %d  \n"
        "Effective %d  Effective %d  \n",
             getuid (),     getgid (),
             geteuid(),     getegid()
    );

    return 0 ;       
}
