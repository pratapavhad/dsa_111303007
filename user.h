typedef struct user {
	char usrnm[8];
	char passwd[16];
	float avgspeed;
	float avgacc;
	float pts;
	int races;
	struct user *next, *prev;
} user;
typedef struct userlist{
        user *head, *tail;
        int length;
}userlist;
void uinit(userlist *l);
void uappend(userlist *l, user def);
void uremove(userlist *l, user def);
user *chkpass(userlist *l, char *usrnm, char *passwd);
