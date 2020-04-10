/*
 * BCFlight
 * Copyright (C) 2016 Adrien Aubry (drich)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <Main.h>

#include <PWM.h>
#include <DShot.h>
#include <OneShot125.h>
void Test( int, char** );

int main( int ac, char** av )
{
// 	Test( ac, av );
/*
	DShot* test1 = new DShot( 26 );
	DShot* test2 = new DShot( 13 );
	DShot* test3 = new DShot( 6 );
	DShot* test4 = new DShot( 5 );
// 	test->SetPWMus( atoi(av[4]) );
// 	test->Update();
*/

	OneShot125* test1 = new OneShot125( 26 );
	OneShot125* test2 = new OneShot125( 13 );
	OneShot125* test3 = new OneShot125( 6 );
	OneShot125* test4 = new OneShot125( 5 );
	test1->setSpeed( 0.0f );
	test2->setSpeed( 0.0f );
	test3->setSpeed( 0.0f );
	test4->setSpeed( 0.0f, true );
	usleep( 1000 * 1000 );
	float sp = 0.0f;
	while ( 1 ) {
		sp += 0.01;
		if ( sp > 1.0f ) {
			sp = 0.0f;
		}
		printf( "sp : %.2f\n", sp );
		test1->setSpeed( sp, true );
		usleep( 500 * 1000 );
	}

	int ret = Main::flight_entry( ac, av );

	if ( ret == 0 ) {
		while ( 1 ) {
			usleep( 1000 * 1000 * 100 );
		}
	}

	return 0;
}
