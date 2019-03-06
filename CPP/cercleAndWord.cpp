//for https://qiita.com/Reputeless/items/7d23879163284261be49
# include <Siv3D.hpp>

void Main()
{
    const Font font(30);

    while (System::Update())
    {
        Circle(Mouse::Pos(), 100).draw();

        font(Mouse::Pos()).draw(50, 200, Palette::Orange);
    }
}
