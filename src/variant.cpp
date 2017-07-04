#include "variant.h"

std::string variant( int vrnt ) {
	switch( vrnt ) {
	case 1:
		return VARIANT_1();
	case 2:
		return VARIANT_2();
	case 3:
		return VARIANT_3();
	case 4:
		return VARIANT_4();
	case 5:
		return VARIANT_5();
	case 6:
		return VARIANT_6();
	case 7:
		return VARIANT_7();
	case 8:
		return VARIANT_8();
	case 9:
		return VARIANT_9();
	case 10:
		return VARIANT_10();
	case 11:
		return VARIANT_11();
	case 12:
		return VARIANT_12();
	case 13:
		return VARIANT_13();
	case 14:
		return VARIANT_14();
	case 15:
		return VARIANT_15();
	case 16:
		return VARIANT_16();
	case 17:
		return VARIANT_17();
	case 18:
		return VARIANT_18();
	case 19:
		return VARIANT_19();
	case 20:
		return VARIANT_20();
	}

	return mock();
}

Variant::Variant( int variant ) : VRNT( variant ) {
	const std::string STG_LIST_DIR( STG_LIST_DIR );
	const std::string STG_LIST_PFX( STG_LIST_PFX );
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
	bool flag = false;

	if( result.compare( "" ) != 0 )
		flag = true;

	if( flag ) {
		for( int i = 0; i < mAlphabet.length(); i++ ) {
			if( result.find( mAlphabet[i] ) ==  std::string::npos) {
				flag = false;
			}
		}
	}

	return flag;
}

bool Variant::isParallel() {
	const std::string output( getOutput() );
	int apos = 0;	// Alphabet position
	int opos = 0;	// Output position
	int counter = 0;// Symbols counter
	bool flag;

	// 1. Т.к. для демонстрации параллельного выполнения необходимо для каждого
	//   потока выводить более одной литеры потока, вывод (output) должен получиться
	//   длиннее, чем алфавит варианта (mAplhabet)

	flag = isLongOutput();

	// 2. Для каждого варианта предусмотрено как минимум два
	//   параллельно выполняемых потока. В этом случае должна
	//   быть как минимум одна прерываемая цепь символов (AAAxxx -> AAxxAx).

	if( flag ) {
		flag = false;
		for( apos = 0; apos < mAlphabet.length(); ++apos ) {
			counter = std::count( output.begin(), output.end(), mAlphabet[apos] );
			if( counter >= 2) {
				opos = output.find( mAlphabet[apos] );
				for( int i = opos + 1; i < opos + counter; ++i) {
					if( output[i] != output[opos] ) {
						return true;
					}
				}
			}
		}
	}

	return flag;
}

std::string Variant::getOutput() {
	std::string buf;

	switch( VRNT ) {
	case DEMO_VRNT:
		buf.assign( "aaacfdbdefbbdbkgmmhkmmbnbnpppp" );
		break;
	default:
		buf.assign( variant( VRNT ) );
		break;
	}

	return buf;
}


bool Variant::isLongOutput() {
	return ( getOutput().length() > mAlphabet.length() );
}

bool Variant::isEstStage( char symbol, int stage ) {
	bool flag = false;

	for( std::list<Stage>::iterator it = mStages.begin(); it != mStages.end(); ++it ) {
		if( it -> stage == stage ) {
			if( it -> stageAlphabet.find( symbol ) != std::string::npos ) {
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
	while( !isEstStage( output[i], stage.stage ) && ( i < output.length() ) ) {
		i++;
	}
	// Копируем элементы, принадлежащие данной очереди
	while( isEstStage( output[i], stage.stage ) && ( i < output.length() ) ) {
		buf.append( 1, output[i] );
		i++;
	}

	return buf;
}
