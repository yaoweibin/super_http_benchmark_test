
#include "sb.h"


/*
 * ./sb -n 10000 -c 100 [-k] http://www.example.org/
 *
 *
 */

void usage() 
{
    printf("Usage: ab [options] [http[s]://]hostname[:port]/path" CRLF
            "Options are:" CRLF
            " -c concurrency  Number of multiple requests to make" CRLF
            " -h              Display usage information (this message)" CRLF
            " -k              Use HTTP KeepAlive feature" CRLF
            " -n requests     Number of requests to perform" CRLF
          );
}


int nr_request = 1;
int nr_concurrency = 1;
int is_keepalive = 0;
char * uri = NULL;

int 
get_options(int argc, char **argv) 
{
    char *p;
    int i;

    for (i = 1; i < argc; i++) {
        p = argv[i];

        if (i == argc - 1) {
            uri = argv[i];
            return 0;
        }

        if (*p++ != '-') {
            printf("invalid option: \"%s\"" CRLF, argv[i]);
            return -1;
        }

        while (*p) {
            switch (*p++) {
            case '?':
            case 'h':
                return -1;

            case 'c':
                if (*p) {
                    nr_concurrency = atoi(p);
                    goto next;
                }
                else if (argv[++i]) {
                    nr_concurrency = atoi((const char *)argv[i]);
                    goto next;
                }

                break;

            case 'k':
                is_keepalive = 1;

                break;

            case 'n':
                if (*p) {
                    nr_request = atoi(p);
                    goto next;
                }
                else if (argv[++i]) {
                    nr_request = atoi((const char *)argv[i]);
                    goto next;
                }

                break;

            default:
                printf("invalid option: \"%s\"" CRLF, argv[i]);
                return -1;
            }
        }

next:

    continue;

    }

    return -1;
}


int 
main(int argc, char **argv) 
{
    if (get_options(argc, argv) == -1) {
        usage();
        exit(1);
    }
    
    printf("nr_request = %d\n", nr_request);
    printf("nr_concurrency = %d\n", nr_concurrency);
    printf("is_keepalive = %d\n", is_keepalive);
    printf("uri = \"%s\"\n", uri);

    return 0;
}
