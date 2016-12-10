/*logger library used to write timestamp'd log messages
Copyright (C) <2014> <Ahmed Fekry nixnub@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define filename "log.txt"
#define create_file 1
#define closefile 1

char hostname[1024];
char *tstamp(void);
int logger(char *msg, int type);
char *tstamp(void) {
        char *month[] = {"Jan", "Feb", "Mar", "Apr",
			 "May", "Jun", "Jul", "Aug",
			 "Sep", "Oct", "Nov", "Dec"};
        time_t ltime;
        struct tm *Tm;
        ltime=time(NULL);
        Tm=localtime(&ltime);
        char *timestamp = malloc(1024 * sizeof(char));
        sprintf((char *)timestamp,"%s %d %d:%d:%d %d",
        month[Tm->tm_mon],
        Tm->tm_mday,
        Tm->tm_hour,
        Tm->tm_min,
        Tm->tm_sec,
        Tm->tm_year+1900);
        return timestamp;
}
int logger(char *text, int type) {
    	gethostname(hostname, 1024);
	//time_t timestamp = time(NULL);
	FILE *fp;
	fp = fopen(filename, "a+");
	fprintf(fp,"%s ", tstamp());
	fprintf(fp,"%s ", hostname);
	switch(type) {
	case 1:	fprintf(fp,"%s ", "[ERROR]:"); break;
	case 2:	fprintf(fp,"%s ", "[WARN]:"); break;
	case 3:	fprintf(fp,"%s ", "[NOTICE]:"); break;
	}
	fprintf(fp, "%s", text);
	fprintf(fp, "\n");
	if ( closefile == 1 ) {
		fclose(fp);
	}
	return 0;
}
