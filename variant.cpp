#include "variant.h"

std::string variant( int vrnt ) {
	//switch( vrnt ) {
	//case 1:
	//	return variant1();
	//	break;
	//case 2:
	//	return variant2();
	//	break;
	//case 3:
	//	return variant3();
	//	break;
	//case 4:
	//	return variant4();
	//	break;
	//case 5:
	//	return variant5();
	//	break;
	//case 6:
	//	return variant6();
	//	break;
	//case 7:
	//	return variant7();
	//	break;
	//case 8:
	//	return variant8();
	//	break;
	//case 9:
	//	return variant9();
	//	break;
	//case 10:
	//	return variant10();
	//	break;
	//case 11:
	//	return variant11();
	//	break;
	//case 12:
	//	return variant12();
	//	break;
	//case 13:
	//	return variant13();
	//	break;
	//case 14:
	//	return variant14();
	//	break;
	//case 15:
	//	return variant15();
	//	break;
	//case 16:
	//	return variant16();
	//	break;
	//case 17:
	//	return variant17();
	//	break;
	//case 18:
	//	return variant18();
	//	break;
	//case 19:
	//	return variant19();
	//	break;
	//case 20:
	//	return variant20();
	//	break;
	//}

	return "";
}

Variant::Variant( int variant ) : VRNT( variant ) {
	const std::string STG_LIST_DIR( "@STG_LIST_DIR@" );
	const std::string STG_LIST_PFX( "@STG_LIST_PFX@" );
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

Variant::Stage& Variant::Stage::operator=( const Variant::Stage& rhs) {
	this -> stage = rhs.stage;
	this -> stageAlphabet.assign( rhs.stageAlphabet );
	return *this;
}

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
	int apos = 0;	// Alphabet position
	int opos = 0;	// Output position
	int counter = 0;// Symbols counter
	bool flag;

	// 1. Для каждого варианта предусмотрено как минимум два
	//   параллельно выполняемых потока. В этом случае должна
	//   быть как минимум одна прерываемая цепь символов (AAAxxx -> AAxxAx).

	flag = isLongOutput();

	// 2. Т.к. для демонстрации параллельного выполнения необходимо для каждого
	//   потока выводить более одной литеры потока, вывод (output) должен получиться
	//   длиннее, чем алфавит варианта (mAplhabet)

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
}

std::string Variant::getOutput() {
	std::string buf;
	int rnd;

	switch( VRNT ) {
	case DEMO_VRNT:
		srand( time ( 0 ) );
		rnd = rand() % 2;	// Чётное-нечетное - 2 варианта
		switch( rnd ) {
		case 0:
			buf.assign( "paaacfdbdefbbdbkgmmhkmmbnbnpppp" );
			break;
		default:
			buf.assign( "aaacfdbdefbbdbkgmmhkmmbnbnnpppp" );
		}
		break;
	default:
		// TODO: !!!! HARDCODE!
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
