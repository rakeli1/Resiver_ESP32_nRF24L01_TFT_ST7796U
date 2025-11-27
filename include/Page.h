#pragma once

class Page
{
  public:
       
       virtual void update() = 0; // обновление информации
       virtual void draw() = 0;   // отрисовка страницы
       virtual ~Page() {}         
};