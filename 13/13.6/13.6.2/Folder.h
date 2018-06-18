#include <set>

class Message;

class Folder
{
	public:
		void addMsg(Message*);
		void remMsg(Message*);
	private:
		std::set<Message*> messages;
};

void Folder::addMsg(Message *rhs)
{
	messages.insert(rhs);
}

void Folder::remMsg(Message *rhs)
{
	messages.erase(rhs);
}
