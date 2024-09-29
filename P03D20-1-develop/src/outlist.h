struct outlist {
    int value;
    struct outlist *next;
};

struct outlist *initOutlist(int value);
struct outlist *addToOutlist(struct outlist *root, int value);
struct outlist *getLastOutElem(struct outlist *root);
char *outlistToStr(struct outlist *root, char *destination);