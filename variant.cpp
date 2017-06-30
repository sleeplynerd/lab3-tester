#include "variant.h"

Variant::Variant( int variant ) : VRNT( variant ) {
	std::string buf;
	std::string filePath( STG_LIST_DIR + "/" + STG_LIST_PFX + std::to_string( VRNT ) );
	std::fstream file( filePath );

	// Первая строка файла - список дуг
	std::getline( file, mAlphabet );
	// Последующие строки - список очередей.
	for( int i = 0; std::getline( file, buf ); i++) {
		mStages.push_back( Stage( buf, i ) );			// Заполняем список очередей
	}
}

Variant::Stage( std::string stageAlphabet, int stageVal) : stageAlphabet( arcsVal ), stage( stageVal ) {}

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
	std::string result( VARIANT( VRNT ) );
	bool flag = true;

	for( int i = 0; i < mAlphabet.length(); i++ ) {
		if( result.find( mAlphabet[i] ) ==  std::string::npos) {
			flag = false;
		}
	}

	return flag;
}

bool Variant::isParallel() {
	const std::string output( VARIANT( VRNT ) );
	std::list<Stage>::iterator it;
	bool flag = true;

	for( it = mStages.begin(); it != mStages.end(); ++it ) {
		flag = flag && isLongStage( it, output ) && isParallelStage( it, output );
		if( !flag ) {
			it = mStages.end();
		}
	}

	return flag;
}

bool Variant::isLongStage( const Stage& stage, const std::string& output ) {
	return ( getStageFragment( stage, output ).length() > ( stage -> stageAlphabet.length() ) );
}


bool Variant::isParallelStage( const Stage& stage, const std::string& output ) {
	std::string sf( getStageFragment( stage, output ) );	// Stage Fragment
	std::string sa( stage -> stageAlphabet );				// Stage Alphabet
	int sfp = 0;											// Stage Fragment Position
	int sap = 0;											// Stage Alphabet Position
	int counter;
	bool flag = false;

	//  Обход каждого элемента "алфавита"
	for( sap = 0; sap < sa.length(); ++sap ) {
		counter = std::count( sf.begin(), sf.end(), sa[sap] );
		// Появление двух и более элементов допускает их взаимные перестановки.
		//   Проверяем, не собрались ли элементы в "цепь" (AAABBB)
		if( counter >= 2 ) {
			sfp = sf.find( sa[sap] );
			// Проверяем, прерываются ли подряд идущие символы другими символами (AABA)
			for( int i = sfp + 1; i < sfp + counter; ++i) {
				if( sf[i] != sa[sap] ) {
					flag = true;
					// Выход из циклов
					sap = sa.length();
					i = sfp + counter;
				}
			}
		}
	}

	return flag;
}

bool Variant::isEstStage( char symbol, int stage ) {
	bool flag = false;

	for( std::list<Stage>::iterator it = mStages.begin(); it != mStages.end(); ++it ) {
		if( it -> stage == stage ) {
			if( it -> arcs.find( symbol ) != std::string::npos ) {
				flag = true;
			}
			break;
		}
	}

	return flag;
}

std::string Variant::getStageFragment( const Stage& stage, const std::string& output ) {
	std::string buf( "" );
	int i = 0;

	// Ищем позицию начала очереди
	while( !isEstStage( output[i], stage -> stage ) && ( i < output.length() ) ) {
		i++;
	}
	// Копируем элементы, принадлежащие данной очереди
	while( isEstStage( output[i], stage -> stage ) && ( i < output.length() ) ) {
		buf.append( output[i] );
		i++;
	}

	return buf;
}
