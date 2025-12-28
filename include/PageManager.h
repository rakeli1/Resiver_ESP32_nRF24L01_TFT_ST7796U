#pragma once
#include "Page.h"
#include "ForecastPage.h"
#include "CurrencyPage.h"

class MainPage;
extern MainPage mainpage;

class PageManager
{
  private:
    Page* currentPage = nullptr; // указатель на текущую страницу
    bool needRedrawstatic = false; // флаг перерисовки статики

    

  public:
    PageManager() = default;
    void setPage(Page* newPage);
    void update();
    Page* getCurrentPage() const;    
};
