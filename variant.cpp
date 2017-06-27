#include "variant.h"

Variant::Stage( std::string arcsVal, int stageVal) : arcs( arcsVal ), stage( stageVal ) {}

bool Variant::isFull() {
	std::string result = VARIANT( VRNT );
}

Variant::Variant( int variant ) : VRNT( variant ) {
	std::string buf;
	std::string stgListPath( STG_LIST_DIR + "/" + STG_LIST_PFX + std::to_string( VRNT ) );
	std::fstream file( stgListPath );
<<<<<<< HEAD

=======
>>>>>>> 4c5acb4b365719a631a62525b860d943e7b02079
	if( file ) {
		std::getline( file, mAlphabet );						// Первая строка - список дуг
		for( int i = 0; std::getline( file, buf ); i++) {
			mStages.push_back( Stage( buf, i ) );			// Заполняем список очередей
		}
	}
}
