.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge_2_Solution - Debug ]----------"
	@cd "Challenge_2_Solution" && "$(MAKE)" -f  "Challenge_2_Solution.mk"
clean:
	@echo "----------Cleaning project:[ Challenge_2_Solution - Debug ]----------"
	@cd "Challenge_2_Solution" && "$(MAKE)" -f  "Challenge_2_Solution.mk" clean
