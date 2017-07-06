#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string>

void* threadFunctionA( void* );
void* threadFunctionB( void* );
void* threadFunctionC( void* );
void* threadFunctionD( void* );
void* threadFunctionE( void* );
void* threadFunctionF( void* );
void* threadFunctionG( void* );
void* threadFunctionH( void* );
void* threadFunctionI( void* );
void* threadFunctionK( void* );

void initSemaphore( sem_t& );
void msg( void* threadLetter, int length, bool isMutexSync );

pthread_mutex_t mutex;

pthread_t threadA;
pthread_t threadB;
pthread_t threadC;
pthread_t threadD;
pthread_t threadE;
pthread_t threadF;
pthread_t threadG;
pthread_t threadH;
pthread_t threadI;
pthread_t threadK;

sem_t semaphoreA;
sem_t semaphoreB;
sem_t semaphoreC;
sem_t semaphoreD;
sem_t semaphoreE;
sem_t semaphoreF;
sem_t semaphoreG;
sem_t semaphoreH;

const static int SHORT = 4;
const static int MEDIUM = 8;
const static int LONG = 12;

std::string output;

std::string variant9() {

    output.assign( "" );

	initSemaphore( semaphoreA );
	initSemaphore( semaphoreB );
	initSemaphore( semaphoreC );
	initSemaphore( semaphoreD );
	initSemaphore( semaphoreE );
	initSemaphore( semaphoreF );
	initSemaphore( semaphoreG );
	initSemaphore( semaphoreH );

	pthread_mutex_init ( &mutex, NULL );

	pthread_create( &threadA, NULL, threadFunctionA, (void*) "A" );
	pthread_create( &threadB, NULL, threadFunctionB, (void*) "B" );
	pthread_create( &threadC, NULL, threadFunctionC, (void*) "C" );
	pthread_create( &threadD, NULL, threadFunctionD, (void*) "D" );
	pthread_create( &threadE, NULL, threadFunctionE, (void*) "E" );
	pthread_create( &threadF, NULL, threadFunctionF, (void*) "F" );
	pthread_create( &threadG, NULL, threadFunctionG, (void*) "G" );
	pthread_create( &threadH, NULL, threadFunctionH, (void*) "H" );
	pthread_create( &threadI, NULL, threadFunctionI, (void*) "I" );
	pthread_create( &threadK, NULL, threadFunctionK, (void*) "K" );

	pthread_join( threadI, NULL );
	pthread_join( threadK, NULL );

    std::cout << output << std::endl;
	//printf( "\n" );

    return output;
}

void msg( void* threadLetter, int length, bool isMutexSync = false ) {
	for( int i = 0; i < length; i++ ) {
		if( isMutexSync ) {
			pthread_mutex_lock( &mutex );
		}

		//printf( "%c", ( (char*) threadLetter )[0] );
        output.append( 1, ( (char*) threadLetter )[0] );

		if( isMutexSync ) {
			pthread_mutex_unlock( &mutex );
		}
	}

}

void initSemaphore( sem_t& semaphore ) {
	int initResult;
	initResult = sem_init( &semaphore, 0,0 );
	if( initResult != 0 ) {
		exit( EXIT_FAILURE );
	}
}

void* threadFunctionA( void* letter ) {
	msg( letter, SHORT, true );
	sem_post( &semaphoreA );
}

void* threadFunctionB( void* letter ) {
	msg( letter, MEDIUM, true );
	sem_post( &semaphoreB );
}

void* threadFunctionC( void* letter ) {
	msg( letter, LONG, true );
	sem_post( &semaphoreC );
	sem_post( &semaphoreC );
	sem_post( &semaphoreC );
}

void* threadFunctionD( void* letter ) {
	sem_wait( &semaphoreA );
	msg( letter, SHORT );
	sem_post( &semaphoreD );
}

void* threadFunctionE( void* letter ) {
	sem_wait( &semaphoreD );
	sem_wait( &semaphoreB );
	msg( letter, SHORT );
	sem_post( &semaphoreE );
	sem_post( &semaphoreE );
	sem_post( &semaphoreE );
}

void* threadFunctionF( void* letter ) {
	sem_wait( &semaphoreC );
	sem_wait( &semaphoreE );
	msg( letter, SHORT, true );
	sem_post( &semaphoreF );
}

void* threadFunctionG( void* letter ) {
	sem_wait( &semaphoreF );
	msg( letter, SHORT );
	sem_post( &semaphoreG );
}

void* threadFunctionH( void* letter ) {
	sem_wait( &semaphoreC );
	sem_wait( &semaphoreE );
	msg( letter, MEDIUM, true );
	sem_post( &semaphoreH );
}

void* threadFunctionI( void* letter ) {
	sem_wait( &semaphoreC );
	sem_wait( &semaphoreE );
	msg( letter, SHORT, true );
}

void* threadFunctionK( void* letter ) {
	sem_wait( &semaphoreH );
	sem_wait( &semaphoreG );
	msg( letter, SHORT );
}
