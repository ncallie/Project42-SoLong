
all: 
	$(MAKE) -C ./so_long_mandatory all

bonus:
	$(MAKE) -C ./so_long_bonus all

clean:
	$(MAKE) -C ./so_long_mandatory clean

clean_bonus:
	$(MAKE) -C ./so_long_bonus clean

fclean: clean
	$(MAKE) -C ./so_long_mandatory fclean

fclean_bonus: clean_bonus
	$(MAKE) -C ./so_long_bonus fclean

