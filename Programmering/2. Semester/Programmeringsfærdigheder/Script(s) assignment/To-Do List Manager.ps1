$tasks = @()

while ($true) {
    Write-Host "1. Add a task"
    Write-Host "2. View all tasks"
    Write-Host "3. Remove a task"
    Write-Host "4. Exit"
    $choose = Read-Host "Choose:"

    switch ($choose) {
        "1" { 
            $task = Read-Host "Write your task"
            $tasks += $task
        }
        "2" { 
            for ($i = 0; $i -lt $tasks.Length; $i++) {
                Write-Host "$($i+1). $($tasks[$i])"
            }
        }
        "3" { 
            $index = (Read-Host "What task would you like to remove?") - 1
            $tasks = $tasks | Where-Object { $tasks.IndexOf($_) -ne $index }
        }
        "4" { 
            exit
        }
    }
}