.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge_4_Solution - Debug ]----------"
	@cd "Challenge_4_Solution" && "$(MAKE)" -f  "Challenge_4_Solution.mk"
clean:
	@echo "----------Cleaning project:[ Challenge_4_Solution - Debug ]----------"
	@cd "Challenge_4_Solution" && "$(MAKE)" -f  "Challenge_4_Solution.mk" clean
