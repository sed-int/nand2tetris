library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Mux is
    Port (
        a, b, sel : in STD_LOGIC;
        out : out STD_LOGIC
    );
end Mux;

architecture Behavioral of Mux is
    signal nsel, x, y : STD_LOGIC;
begin
    NotGate: process (sel)
    begin
        nsel <= not sel;
    end process NotGate;

    AndGate1: process (a, sel)
    begin
        x <= a and sel;
    end process AndGate1;

    AndGate2: process (nsel, b)
    begin
        y <= nsel and b;
    end process AndGate2;

    OrGate: process (x, y)
    begin
        out <= x or y;
    end process OrGate;

end Behavioral;
