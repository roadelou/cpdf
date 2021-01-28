/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-01-28
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

// Used for printf, snprintf and puts
#include <stdio.h>

// Used for command line arguments
#include <getopt.h>

// Used for system call
#include <stdlib.h>

// Used for strlen
#include <string.h>

// Used for alloca
#include <alloca.h>

/********************************* PROTOYPES **********************************/

/* The prototypes of your functions go here. */

/************************************ MAIN ************************************/

int main(int argc, char *const *argv) {
    // Return code of getopt
    int opt;
    // Described the possible short arguments to getopt.
    const char *optstring = "l:m:h:";
    // Describes the possible long arguments to getopt.
    const struct option long_options[] = {
        {"low", no_argument, 0, 'l'},
        {"medium", no_argument, 0, 'm'},
        {"high", no_argument, 0, 'h'},
    };
    // Using ebook as default compression level.
    char *compression = "ebook";
    // We first parse the command line arguments with getopt.
    while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) !=
           -1) {
        switch (opt) {
        case 'l':
            // Using screen compression.
            compression = "screen";
            break;
        case 'm':
            // Using ebook compression, the default.
            compression = "ebook";
            break;
        case 'h':
            // Using prepress compression.
            compression = "prepress";
            break;
        default:
            // No need to send an error message, getopt does that already.
            // Exiting with return code -1.
            return -1;
        }
    }
    // Getting input file path first.
    if (optind >= argc) {
        // No more arguments available, the input file was not provided.
        fputs("No input file provided", stderr);
        // Failling with error code -2.
        return -2;
    }

    // Reading the input file from argv.
    const char *input_file = argv[optind];

    // Getting the output file second.
    if (optind + 1 >= argc) {
        // No more arguments available, the output file was not provided.
        fputs("No output file provided", stderr);
        // Failling with error code -3.
        return -3;
    }

    // Reading the output file from argv.
    const char *output_file = argv[optind + 1];

    // The format string used to build the ghostscript command.
    const char *ghostscript_format =
        "ghostscript -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/%s "
        "-dNOPAUSE -dQUIET -dBATCH -sOutputFile=%s %s";
    // Allocating a buffer wide enough for the command line argument of
    // ghostscript. Note that there are 3 '%s' characters that will be removed
    // in the ghostscript_format string, and that we have to account for the
    // null-terminating byte.
    int buffer_size = (strlen(output_file) + strlen(input_file) +
                       strlen(compression) + strlen(ghostscript_format) - 2);
    char *ghostscript_call = alloca(buffer_size * sizeof(char));
    // Building the command line argument.
    snprintf(ghostscript_call, buffer_size, ghostscript_format, compression,
             output_file, input_file);

    // Calling ghostscript through the shell.
    return system(ghostscript_call);
}

/********************************* FUNCTIONS **********************************/

/* The functions for your code go here. */

/************************************ EOF *************************************/
