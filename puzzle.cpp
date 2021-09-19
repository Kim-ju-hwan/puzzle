#include <bangtal>
using namespace bangtal;

//x,y,좌표와 object를 입력받아 조각을 저장한다.
class Piece {
public:
	ObjectPtr object;
	ScenePtr scene;
	int x, y;
	Piece(int x, int y, ObjectPtr object,ScenePtr scene) :x(x), y(y), object(object),scene(scene) {};	
};

void change(Piece *piece1, Piece *piece2) {
	piece1->object->locate(piece1->scene, piece2->x, piece2->y);
	piece2->object->locate(piece2->scene, piece1->x, piece1->y);
}

int main()
{
	ScenePtr scene;
	//필요없는 옵션 제거
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	scene = Scene::create("퍼즐 ", "Images/배경.png");

	
	//조각들 위치 설정, 이미지 배정
	const int x[3] = { 255,425,590 };
	const int y[3] = { 400,660,915 };
	auto piece1 = Object::create("Images/모나리자1.png", scene,x[1], y[2]);
	piece1->setScale(0.5f);
	Piece piece_1(x[1], y[2], piece1,scene);
	auto piece2 = Object::create("Images/모나리자2.png", scene, x[0], y[2]);
	piece2->setScale(0.5f);
	Piece piece_2(x[0], y[2], piece2, scene);
	auto piece3 = Object::create("Images/모나리자3.png", scene, x[1], y[1]);
	piece3->setScale(0.5f);
	Piece piece_3(x[1], y[1], piece3, scene);
	auto piece4 = Object::create("Images/모나리자4.png", scene, x[0], y[0]);
	piece4->setScale(0.5f);
	Piece piece_4(x[0], y[0], piece4, scene);
	auto piece5 = Object::create("Images/모나리자5.png", scene, x[2], y[2]);
	piece5->setScale(0.5f);
	Piece piece_5(x[2], y[2], piece5, scene);
	auto piece6 = Object::create("Images/모나리자6.png", scene, x[2], y[1]);
	piece6->setScale(0.5f);
	Piece piece_6(x[2], y[1], piece6, scene);
	auto piece7 = Object::create("Images/모나리자7.png", scene, x[0], y[1]);
	piece7->setScale(0.5f);
	Piece piece_7(x[0], y[1], piece7, scene);
	auto piece8 = Object::create("Images/모나리자8.png", scene, x[1], y[0]);
	piece8->setScale(0.5f);
	Piece piece_8(x[1], y[0], piece8, scene);
	auto blank = Object::create("Images/빈칸.png", scene, x[2], y[0]);
	blank->setScale(0.5f);
	Piece Blank(x[2], y[0], blank, scene);

	int a, b;

	//마우스로 클릭하면 빈칸으로 이동하도록 설정

	piece1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_1, &Blank);
		a = piece_1.x;
		b = piece_1.y;
		piece_1.x = Blank.x;
		piece_1.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_2, &Blank);
		a = piece_2.x;
		b = piece_2.y;
		piece_2.x = Blank.x;
		piece_2.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_3, &Blank);
		a = piece_3.x;
		b = piece_3.y;
		piece_3.x = Blank.x;
		piece_3.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_4, &Blank);
		a = piece_4.x;
		b = piece_4.y;
		piece_4.x = Blank.x;
		piece_4.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_5, &Blank);
		a = piece_5.x;
		b = piece_5.y;
		piece_5.x = Blank.x;
		piece_5.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_6, &Blank);
		a = piece_6.x;
		b = piece_6.y;
		piece_6.x = Blank.x;
		piece_6.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_7, &Blank);
		a = piece_7.x;
		b = piece_7.y;
		piece_7.x = Blank.x;
		piece_7.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	piece8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		change(&piece_8, &Blank);
		a = piece_8.x;
		b = piece_8.y;
		piece_8.x = Blank.x;
		piece_8.y = Blank.y;
		Blank.x = a;
		Blank.y = b;
		return true;
		});

	//게임을 종료하는 버튼
	auto button = Object::create("Images/성공.png", scene, 0, 400);
	button->setScale(0.2f);
	button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});

	//게임방법 설명하는 버튼 생성
	auto howto = Object::create("Images/게임방법.png", scene, 0, 1000);
	howto->setScale(0.8f);

	auto explain = Object::create("Images/how.png", scene, 25, 600, false);
	explain->setScale(1.5f);

	howto->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		explain->show();
		return true;
		});

	explain->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		explain->hide();
		return true;
		});

	//60초 타이머 생성
	auto timer1 = Timer::create(60);
	showTimer(timer1);
	timer1->start();

	timer1->setOnTimerCallback([&](TimerPtr timer)->bool {
		showMessage("실패ㅠㅠ");
		auto timer2 = Timer::create(1);
		timer2->start();

		timer2->setOnTimerCallback([&](TimerPtr timer)->bool {
			endGame();
			return true;
			});
		return true;
		});


	showMessage("제한시간은 1분! 퍼즐을 풀어보세요. ");
	startGame(scene);
}