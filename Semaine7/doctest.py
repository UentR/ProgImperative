import tempfile
import subprocess
import sys


ipython = get_ipython()


def hide_traceback(exc_tuple=None, filename=None, tb_offset=None,
                   exception_only=False, running_compiled_code=False):
    etype, value, tb = sys.exc_info()
    exception = ipython.InteractiveTB.get_exception_only(etype, value)
    return ipython._showtraceback(etype,
                                  value,
                                  exception
                                  )


ipython.showtraceback = hide_traceback


def doctest(file: str, test: str) -> bool:
    # Workaround: unlike xeus-cling, cling does supports utf-8, but in
    # included file only, not interactively
    # https://github.com/root-project/cling/issues/497

    # To be able to call test functions with accents in them, we put the
    # function call in a function defined in a temporary file and include it.
    with tempfile.NamedTemporaryFile() as tmp:
        tmp.write(f'#include "{file}"\n void _doctest_() {{ {test}(); }}'.encode())
        tmp.flush()
        res = subprocess.run("cling",
                             input=f'#include "{tmp.name}"\n _doctest_();'.encode(),
                             capture_output=True)
    if res.stderr:
        lines = res.stderr.decode().splitlines()
        # If cling crashes, hide the stack trace and everything after
        if "Stack dump:" in lines:
            lines = lines[:lines.index("Stack dump:")]
        lines = [line for line in lines if not line.startswith("cling(")]
        raise RuntimeError("\n"+'\n'.join(lines))
