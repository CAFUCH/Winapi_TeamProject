#include "pch.h"
#include "Panel.h"
#include "Texture.h"
Panel::Panel()
{
}

Panel::~Panel()
{
}

void Panel::Init()
{

}

void Panel::Update()
{
}

void Panel::Render(HDC _dc)
{
	if (enabled == true) {

		if (nullptr != tex) {
			float Width = tex->GetWidth();
			float Height = tex->GetHeight();

			BitBlt(_dc, 0, 0, (int)Width, (int)Height, tex->GetDC(), 0, 0, SRCCOPY);
		}
	}
}

void Panel::SetTexture(Texture* _tex)
{
	tex = _tex;
}
