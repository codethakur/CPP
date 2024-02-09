class Entity {
public:
		virtual void printName(){}
};

class Player :public Entity {

};

class Enamy :public Entity {

};

int main()
{
	Entity* player = new Player();

	Entity* actuallyEnamy = new Enamy();

	Entity* acctuallyPlayer = player;


	Player* p0 = static_cast<Player*> (actuallyEnamy);
	Player* p1 = dynamic_cast<Player*> (acctuallyPlayer);

}
