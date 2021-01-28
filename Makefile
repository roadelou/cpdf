################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2021-01-28
# Language: Makefile

################################### ALIASES ####################################

# Source files
src = main.c
# Built executable
exec = cpdf.elf
# Installed executable
dist = $(DESTDIR)/usr/bin/cpdf

################################### SPECIAL ####################################

.PHONY: install clean uninstall

#################################### RULES #####################################

$(exec): $(src)
	$(CC) -Wall -pedantic $(src) -o $(exec)

install: $(exec)
	mv $(exec) $(dist)

uninstall:
	rm -f $(dist)

clean:
	rm -f $(exec)

##################################### EOF ######################################
