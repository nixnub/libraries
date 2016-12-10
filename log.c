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

#include "log.h"

int main(void) {
    logger("this is an error message", 1);
    logger("This is a Warning message", 2);
    logger("This is a Notice", 3); 
    return 0;
}
