!
! test/data/data_generator.f90
!

module utilities

implicit none

contains

function get_free_file_unit() result(file_unit)
  implicit none
  integer :: file_unit
  integer :: i
  logical :: od
  integer :: ios
  file_unit = -1
  do i = 0, 99
    inquire(unit=i, opened=od, iostat=ios)
    if ((ios == 0) .and. (.not. od)) then
      file_unit = i
      exit
    end if
  end do
end function

end module utilities

program data_generator

  use utilities

  implicit none

  integer :: exint
  real (kind=4) :: exrealk4
  real (kind=8) :: exrealk8
  logical :: exlogical
  character(len=128) :: exchararray

  integer :: a(5)

  namelist /nmlexint/ exint
  namelist  /nmlexrealk4/ exrealk4
  namelist /nmlexrealk8/ exrealk8
  namelist /nmlexlogical/ exlogical
  namelist /nmlexchararray/ exchararray

  integer :: file_unit

  exint = 3
  exrealk4 = 3.3
  exrealk8 = 3.3
  exlogical = .true.
  exchararray = "hello world!"

  file_unit = get_free_file_unit()

  open(file_unit, file="nmlexint.txt")
  write (file_unit, nml=nmlexint)
  close(file_unit)

  open(file_unit, file="nmlexreal4.txt")
  write (file_unit, nml=nmlexrealk4)
  close(file_unit)

  open(file_unit, file="nmlexreal8.txt")
  write (file_unit, nml=nmlexrealk8)
  close(file_unit)

  open(file_unit, file="nmlexlogical.txt")
  write (file_unit, nml=nmlexlogical)
  close(file_unit)

  open(file_unit, file="nmlexchararray.txt")
  write (file_unit, nml=nmlexchararray)
  close(file_unit)

end program data_generator
