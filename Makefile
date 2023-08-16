CXX = g++
CXXFLAGS = -Wall -Werror -Iinclude -std=c++20 -O2 -g
SRCDIR = src
OBJDIR = obj

SRC = $(shell ls $(SRCDIR)/*.cc)
OBJ = $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SRC))
SRC += main.cc
all: expr

expr: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

.PHONY:clean format
clean:
	rm -rf $(OBJDIR) expr
format:
	clang-format -style=file $(SRC)

