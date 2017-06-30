#include "variant.h"

Variant::Variant( int variant ) : VRNT( variant ) {
	static const std::string STG_LIST_DIR( "@STG_LIST_DIR@" );
	static const std::string STG_LIST_PFX( "@STG_LIST_PFX@" );
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

Variant::Variant() : VRNT( DEMO_VRNT ) {
	mAlphabet.assign( "abcdefghkmnp" );
	mStages.push_back( Stage( "a", 0) );
	mStages.push_back( Stage( "cdfb", 1 ) );
	mStages.push_back( Stage( "edfb", 2 ) );
	mStages.push_back( Stage( "kgmb", 3 ) );
	mStages.push_back( Stage( "khmb", 4 ) );
	mStages.push_back( Stage( "nb", 5 ) );
	mStages.push_back( Stage( "p", 6 ) );
}

Variant::Variant( const std::string& alphabet,
	const std::list<Stage>& stages,
	const int& variant ) : VRNT( variant ) {

	mAlphabet.assign( alphabet );
	mStages.assign( stages.begin(), stages.end() );

}

Variant::Stage::Stage( std::string alphVal, int stageVal) : stageAlphabet( alphVal ), stage( stageVal ) {}

bool Variant::isOrdered() {
	std::string buf( getOutput() );
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
	std::string	buf = getOutput();
	bool flag = false;

	for( int i = 0; i < N_LAUNCHES; i++ ) {
		if( buf.compare( getOutput() ) != 0 ) {
			flag = true;
			//i = N_LAUNCHES;
			break;
		}
	}

	return flag;
}

bool Variant::isFull() {
	std::string result( getOutput() );
	bool flag = true;

	for( int i = 0; i < mAlphabet.length(); i++ ) {
		if( result.find( mAlphabet[i] ) ==  std::string::npos) {
			flag = false;
		}
	}

	return flag;
}

bool Variant::isParallel() {
	const std::string output( getOutput() );
	std::list<Stage>::iterator it;
	bool flag = isLongOutput();

	if( flag ) {
		for( it = mStages.begin(); it != mStages.end(); ++it ) {
			flag = flag && isParallelStage( it, output );
			if( !flag ) {
				it = mStages.end();
			}
		}
	}

	return flag;
}

std::string Variant::getOutput() {
	std::string buf;
	int rnd;

	switch( VRNT ) {
	case DEMO_VRNT:
		srand( ctime ( 0 ) );
		rnd = rand() % 2;	// Чётное-нечетное - 2 варианта
		switch( rnd ) {
		case 0:
			buf.assign( "aaacfdbdefbbdbkgmmhkmmbnbnpppp" );
			break;
		default:
			buf.assign( "aaacfdbdefbbdbkgmmhkmmbnbnnpppp" );
		}
		break;
	default:
		buf.assign( VARIANT( VRNT ) );
		break;
	}

	return buf;
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
		} else {
			flag = true;
		}
	}

	return flag;
}

bool Variant::isLongOutput() {
	return ( getOutput().length() > mAlphabet.length() );
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
