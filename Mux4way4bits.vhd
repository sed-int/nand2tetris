--------------------------------------------------------------------------------
-- Project :
-- File    :
-- Autor   :
-- Date    :
--
--------------------------------------------------------------------------------
-- Description :
--
--------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Mux4way4bits IS
  PORT (
  ------------------------------------------------------------------------------
  --Insert input ports below
    clock      : IN  std_logic;                    -- input bit example
    val        : IN  std_logic_vector(3 DOWNTO 0); -- input vector example
  ------------------------------------------------------------------------------
  --Insert output ports below
    max        : OUT std_logic;                    -- output bit example
    cpt        : OUT std_logic_vector(3 DOWNTO 0)  -- output vector example
    );
END Mux4way4bits;

--------------------------------------------------------------------------------
--Complete your VHDL description below
--------------------------------------------------------------------------------

ARCHITECTURE TypeArchitecture OF Mux4way4bits IS

BEGIN


END TypeArchitecture;
