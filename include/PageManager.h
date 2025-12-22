#pragma once
#include "Page.h"

class MainPage;
class ForecastPage;

class PageManager
{
  private:
    Page* currentPage = nullptr; // указатель на текущую страницу
    bool needRedrawstatic = false; // флаг перерисовки статики

    MainPage* mainpage = nullptr;
    ForecastPage* forecastpage = nullptr;
    // SettingsPage* settingspage;
    // CurrencyPage currencypage;

    PageManager() = default;

  public:
    void setPage(Page* newPage);
    void update();
    Page* getCurrentPage() const;    
};
