#define HelloWorld Hello world
#define Hello(a) Hello there a

HelloWorld;
Hello(class);

#define SQUARE_BAD(a) a * a

SQUARE_BAD(5);
SQUARE_BAD(5 + 1);

#define SQUARE(a) ((a) * (a))

SQUARE(5);
SQUARE(5 + 1);

#define DUMMY(a,b) (a) and (b)

DUMMY(first, second);
DUMMY({first, second});
DUMMY([first, second]);

#define STRINGIZE(a) a vs "a" vs #a

STRINGIZE(x == 0);

#define STR(s) #s
#define XSTR(s) str(s)
#define FOO 4

STR(FOO);
XSTR(FOO);

#define CONCAT(a,b) a ## b
CONCAT(hello, there);

void help_command(void) { ... };
void quit_command(void) { ... };

struct command {
    char* name;
    void (*function) (void);
};

#define COMMAND(name) { #name, name ## _command }

struct command commands[] = {
    COMMAND(help),
    COMMAND(quit)
};

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

eprintf("Error: %s failed %d times!\n", "func", 10);
