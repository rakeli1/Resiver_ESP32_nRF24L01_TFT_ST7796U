#pragma once
#include "Page.h"
#include "ForecastPage.h"

class ForecastPage;
class MainPage;
extern MainPage mainpage;

class PageManager
{
  private:
    Page* currentPage = nullptr; // указатель на текущую страницу
    bool needRedrawstatic = false; // флаг перерисовки статики

    MainPage* mainpage = nullptr;
    ForecastPage* forecastpage = nullptr;
    // SettingsPage* settingspage;
    // CurrencyPage currencypage;

    

  public:
    PageManager() = default;
    void setPage(Page* newPage);
    void update();
    Page* getCurrentPage() const;    
};
