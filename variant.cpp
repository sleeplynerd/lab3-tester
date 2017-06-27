#include "variant.h"

Variant::Stage( std::string arcsVal, int stageVal) : arcs( arcsVal ), stage( stageVal ) {}

bool Variant::isFull() {
	std::string result = VARIANT( VRNT );
}

Variant::Variant( int variant ) : VRNT( variant ) {
	std::string buf;
	std::string stgListPath( STG_LIST_DIR + "/" + STG_LIST_PFX + std::to_string( VRNT ) );
	std::fstream file( stgListPath );

	if( file ) {
		std::getline( file, mAlphabet );						// Первая строка - список дуг
		for( int i = 0; std::getline( file, buf ); i++) {
			mStages.push_back( Stage( buf, i ) );			// Заполняем список очередей
		}
	}
}
