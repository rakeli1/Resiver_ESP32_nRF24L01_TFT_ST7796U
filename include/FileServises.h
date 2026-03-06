#pragma once

enum NetState
{
   IDLE,         // готовимся к запросу
   CONNECTING,      // начинаем соединение
   WAIT_RESPONSE,  //ждем собраного ответа
   DONE,         // данные готовы, можно передать UI
   ERROR         // ошибка можно повторить
};

enum CurrencyId
 {
    USD,
    CAD,
    GBP,
    AUD,
    NZD,
    EUR,
    CHF,
    JPY,
    SGD,
    HKD,
    SEK, 
    SAR_,
    TRY,
    NOK,
    MDL,
    MXN,
    ILS,
    XAG,
    XPT,
    XPD,
    XAU,
    CURRENCYZERO
  };

  enum ParthDayID
  {
   DATA1,
   NIGHT1,  
   MORNING1,
   DAY1,
   EVENING1,
   DATAZERO1,
   NIGHTZERO1,
   MORNINGZERO1,
   DAYZERO1,
   EVENINGZERO1,
   DATA2,
   NIGHT2,  
   MORNING2,
   DAY2,
   EVENING2,
   DATA3,
   NIGHT3,  
   MORNING3,
   DAY3,
   EVENING3,
   DATA4,
   NIGHT4,  
   MORNING4,
   DAY4,
   EVENING4,
   DATA5,
   NIGHT5,  
   MORNING5,
   DAY5,
   EVENING5,
   DATA6,
   NIGHT6,  
   MORNING6,
   DAY6,
   EVENING6,
   PARTHZERO,
  };