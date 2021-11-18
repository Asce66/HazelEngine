#include<Hazel.h>
class SandBox :public Hazel::Application
{
public:
	SandBox();
	~SandBox();

private:

};

SandBox::SandBox()
{

}

SandBox::~SandBox()
{

}
Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}
