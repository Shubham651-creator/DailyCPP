
# Diamond inheritance 

                                player (base class)
                                        |
                                        |
                                        |
                                        |
                                Cricketer: public player
                                        |
                                        |
                        -----------------------------------------
                        |                                       |
                        |                                       |
    Batsman: virtual public Cricketer        Bowlwer: virtual public Cricketer
                        |                                       |
                        |                                       |
                        -----------------------------------------
                                            |
                                            |
                            AllRounder: public Batsman, public Bolwer