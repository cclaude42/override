

void log_wrapper(FILE *logfile, char *log, char *filename)
{
    char buf[256];
   
    strcpy(buf, log);
    snprintf(buf, 254 - strlen(buf), filename);

    buf[strcspn(buf, "\n")] = 0;

    fprintf(logfile, "LOG: %s\n", buf);

    return;
}


int main (int argc, char **argv)
{
    FILE    *logfile;
    int     file;
    int     filebak;
    char    filename[110] = "./backups/";
    char    c;

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

    strncat(filename, argv[1], 99 - strlen(argv[1]));
    filebak = open(filename, 0xc1, 0x1b0);

    if (filebak <= -1) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    c = fgetc(file);
    while (c != -1) {
        write(filebak, &c, 1);
        c = fgetc(file);
    }

    log_wrapper(logfile, "Finished back up ", argv[1]);

    fclose(file);
    close(filebak);

    return 0;
}