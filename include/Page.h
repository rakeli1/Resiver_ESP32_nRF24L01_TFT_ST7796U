#pragma once

class Page
{
  public:
       
       virtual void updateDinamic() = 0; // обновление информации
       virtual void drawStatic() = 0;   // отрисовка страницы
       virtual ~Page() {}         
};