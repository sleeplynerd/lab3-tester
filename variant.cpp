#include "variant.h"

Variant::Stage( std::string arcsVal, int stageVal) : arcs( arcsVal ), stage( stageVal ) {}

Variant::Variant( int variant ) : vrnt( variant ) {
	std::string buf;
	std::string stgListPath( stgListDir + "/" + stgListPfx + stgListPfx + std::to_string( vrnt ) );
	std::fstream file( stgListPath );
	
	if( file ) {
		std::getline( file, alphabet );						// Первая строка - список дуг
		for( int i = 0; std::getline( file, buf ); i++) {
			stages.push_back( Stage( buf, i ) );			// Заполняем список очередей
		}
	}
}
