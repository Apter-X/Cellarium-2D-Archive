typedef struct coordonnees coordonnees;
typedef struct stat stat;

struct coordonnees
{
    int x;
    int y;
};

struct stat
{
    int life;
    int power;

    char material[3];
};