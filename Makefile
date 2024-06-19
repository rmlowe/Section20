.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge_3_Solution - Debug ]----------"
	@cd "Challenge_3_Solution" && "$(MAKE)" -f  "Challenge_3_Solution.mk"
clean:
	@echo "----------Cleaning project:[ Challenge_3_Solution - Debug ]----------"
	@cd "Challenge_3_Solution" && "$(MAKE)" -f  "Challenge_3_Solution.mk" clean
