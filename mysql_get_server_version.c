/* Copyright (C) 2005, 2006 Hartmut Holzgraefe

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
*/

/*
 * MySQL C client API example: mysql_get_server_version()
 *
 * see also http://mysql.com/mysql_get_server_version
*/

#include <stdlib.h>
#include <stdio.h>

#include <mysql.h>

int main(int argc, char **argv) 
{
#if MYSQL_VERSION_ID >= 40100
	MYSQL *mysql = NULL;

	mysql = mysql_init(mysql);

	if (!mysql) {
		puts("Init faild, out of memory?");
		return EXIT_FAILURE;
	}
	
	if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
							"localhost", /* server hostname or IP address */ 
							"root",      /* mysql user */
							"",          /* password */
							"test",      /* default database to use, NULL for none */
							0,           /* port number, 0 for default */
							NULL,        /* socket file or named pipe name */
							CLIENT_FOUND_ROWS /* connection flags */ )) {
		puts("Connect failed\n");
	} else {
		printf("MySQL Server Version: %lu\n", mysql_get_server_version(mysql));
	}

	
	mysql_close(mysql);
#else
	printf("mysql_get_server_version() is only available starting with MySQL 4.1.0\n");
#endif

	return EXIT_SUCCESS;
}