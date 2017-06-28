#include "variant.h"

Variant::Variant( int variant ) : VRNT( variant ) {
	std::string buf;
	std::string stgListPath( STG_LIST_DIR + "/" + STG_LIST_PFX + std::to_string( VRNT ) );
	std::fstream file( stgListPath );

	std::getline( file, mAlphabet );					// Первая строка - список дуг
	for( int i = 0; std::getline( file, buf ); i++) {
		mStages.push_back( Stage( buf, i ) );			// Заполняем список очередей
	}
}

Variant::Stage( std::string arcsVal, int stageVal) : arcs( arcsVal ), stage( stageVal ) {}

bool Variant::isOrdered() {
	std::string buf( VARIANT( VRNT ) );
	bool flag = true;
	int currStage = 0;

	for( int i = 0; i < buf.length(); i++ ) {
		if( isEstStage( buf[i], currStage ) );				// Символ относится к текущей очереди
		else if( isEstStage( buf[i], currStage + 1 ) ) {	// Символ относится к следующей очереди
			currStage++;
		} else {
			flag = false;									// Порядок очередей нарушен
		}
	}

	return flag;
}

bool Variant::isRandom() {
	const int N_LAUNCHES = 100;
	std::string	buf = VARIANT( VRNT );
	bool flag = false;

	for( int i = 0; i < N_LAUNCHES; i++ ) {
		if( buf.compare( VARIANT( VRNT ) ) != 0 ) {
			flag = true;
			//i = N_LAUNCHES;
			break;
		}
	}

	return flag;
}

bool Variant::isFull() {
	std::string result = VARIANT( VRNT );
	bool flag = true;

	for( int i = 0; i < mAlphabet.length(); i++ ) {
		if( result.find( mAlphabet[i] ) ==  std::string::npos) {
			flag = false;
		}
	}

	return flag;
}

bool Variant::isEstStage( char symbol, int stage ) {
	bool flag = false;

	for( std::list<Stage>::iterator it = mStages.begin(); it!= mStages.end(); ++it ) {
		if( it -> stage == stage ) {
			if( it -> arcs.find( symbol )  != std::string::npos ) {
				flag = true;
			}
			break;
		}
	}
}
