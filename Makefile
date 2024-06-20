.PHONY: clean All

All:
	@echo "----------Building project:[ Stack - Debug ]----------"
	@cd "Stack" && "$(MAKE)" -f  "Stack.mk"
clean:
	@echo "----------Cleaning project:[ Stack - Debug ]----------"
	@cd "Stack" && "$(MAKE)" -f  "Stack.mk" clean
